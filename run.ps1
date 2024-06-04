param (
    [string]$outputFile
)

if ($args[0] -eq "-h") {
    Write-Host "Usage: ./run.ps1 [output_file]"
    Write-Host "If output_file is not provided, output will be printed only to stdout"
    exit
}

g++ main.cpp -o main
if ($LASTEXITCODE -ne 0) {
    Write-Host "Compilation failed."
    exit $LASTEXITCODE
}

if ($outputFile) {
    ./main | Tee-Object -FilePath $outputFile | Out-Host
} else {
    ./main | Out-Host
}
